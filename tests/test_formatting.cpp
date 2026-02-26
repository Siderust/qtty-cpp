// SPDX-License-Identifier: AGPL-3.0-or-later
// Copyright (C) 2026 Vallés Puig, Ramon

/**
 * @file test_formatting.cpp
 * @brief Tests for Quantity string formatting: operator<<, format(), and
 *        std::formatter (C++20).
 *
 * These tests verify that every formatting annotation available in Rust
 * (Display `{}`, `{:.N}`, `{:e}`, `{:.Ne}`, `{:E}`, `{:.NE}`) is matched
 * by the corresponding C++ facility.
 *
 * Rust ↔ C++ mapping
 * ------------------
 *   Rust `{}`          →  operator<< (default)  /  format(-1, QTTY_FMT_DEFAULT)
 *   Rust `{:.2}`       →  std::setprecision(2) << std::fixed  /  format(2)
 *   Rust `{:e}`        →  std::scientific  /  format(-1, QTTY_FMT_LOWER_EXP)
 *   Rust `{:.4e}`      →  std::scientific << std::setprecision(4)  /  format(4, QTTY_FMT_LOWER_EXP)
 *   Rust `{:E}`        →  format(-1, QTTY_FMT_UPPER_EXP)
 *   Rust `{:.4E}`      →  format(4,  QTTY_FMT_UPPER_EXP)
 */

#include "fixtures.hpp"
#include <iomanip>
#include <sstream>
#include <string>

// ─── Helper ─────────────────────────────────────────────────────────────────

/// Stream a quantity with the given manipulators and return the string.
template <typename Q>
static std::string stream_qty(const Q &q) {
  std::ostringstream oss;
  oss << q;
  return oss.str();
}

template <typename Q, typename... Manips>
static std::string stream_qty_with(const Q &q, Manips &&...manips) {
  std::ostringstream oss;
  // Apply all manipulators and then stream the quantity
  (oss << ... << std::forward<Manips>(manips)) << q;
  return oss.str();
}

// Fixture used for all formatting tests
class FormattingTest : public QttyTest {};

// ─────────────────────────────────────────────────────────────────────────────
// operator<< tests (mirrors Rust Display `{}`)
// ─────────────────────────────────────────────────────────────────────────────

TEST_F(FormattingTest, StreamDefaultDecimal) {
  Second s(1234.56789);
  // std::ostream default precision is 6 significant digits.
  EXPECT_EQ(stream_qty(s), "1234.57 s");
}

TEST_F(FormattingTest, StreamPrecisionFixed) {
  Second s(1234.56789);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << s;
  EXPECT_EQ(oss.str(), "1234.57 s");
}

TEST_F(FormattingTest, StreamScientificLower) {
  Second s(1234.56789);
  std::ostringstream oss;
  oss << std::scientific << s;
  // std::scientific produces at least 2-digit exponents on most platforms;
  // just check the number part and the unit suffix.
  std::string result = oss.str();
  // Must end with " s"
  EXPECT_EQ(result.back(), 's');
  // Must contain 'e'
  EXPECT_NE(result.find('e'), std::string::npos);
}

TEST_F(FormattingTest, StreamScientificLowerWithPrecision) {
  Second s(1234.56789);
  std::ostringstream oss;
  oss << std::scientific << std::setprecision(4) << s;
  std::string result = oss.str();
  EXPECT_NE(result.find('e'), std::string::npos);
  EXPECT_TRUE(result.find("1.2346e") != std::string::npos ||
              result.find("1.2346E") != std::string::npos)
      << "Got: " << result;
}

TEST_F(FormattingTest, StreamDefaultMeter) {
  Meter m(42.0);
  EXPECT_EQ(stream_qty(m), "42 m");
}

TEST_F(FormattingTest, StreamNegativeValue) {
  Meter m(-42.5);
  EXPECT_EQ(stream_qty(m), "-42.5 m");
}

TEST_F(FormattingTest, StreamKilometerConvertedValue) {
  Kilometer km(1.5);
  EXPECT_EQ(stream_qty(km), "1.5 km");
}

// ─────────────────────────────────────────────────────────────────────────────
// format() method tests (mirrors Rust Display/LowerExp/UpperExp)
// ─────────────────────────────────────────────────────────────────────────────

TEST_F(FormattingTest, FormatDefaultNoPrecision) {
  Second s(1234.56789);
  EXPECT_EQ(s.format(), "1234.56789 s");
}

TEST_F(FormattingTest, FormatDefaultTwoDecimalPlaces) {
  Second s(1234.56789);
  EXPECT_EQ(s.format(2), "1234.57 s");
}

TEST_F(FormattingTest, FormatDefaultZeroDecimalPlaces) {
  Second s(1234.56789);
  EXPECT_EQ(s.format(0), "1235 s");
}

TEST_F(FormattingTest, FormatDefaultFiveDecimalPlaces) {
  Second s(1234.56789);
  EXPECT_EQ(s.format(5), "1234.56789 s");
}

TEST_F(FormattingTest, FormatLowerExpNoPrecision) {
  Second s(1234.56789);
  // Rust {:e} → Rust compact form: 1.23456789e3 s
  EXPECT_EQ(s.format(-1, QTTY_FMT_LOWER_EXP), "1.23456789e3 s");
}

TEST_F(FormattingTest, FormatLowerExpFourDecimalPlaces) {
  Second s(1234.56789);
  // Rust {:.4e} → 1.2346e3 s
  EXPECT_EQ(s.format(4, QTTY_FMT_LOWER_EXP), "1.2346e3 s");
}

TEST_F(FormattingTest, FormatLowerExpZeroDecimalPlaces) {
  Second s(1234.56789);
  EXPECT_EQ(s.format(0, QTTY_FMT_LOWER_EXP), "1e3 s");
}

TEST_F(FormattingTest, FormatUpperExpNoPrecision) {
  Second s(1234.56789);
  EXPECT_EQ(s.format(-1, QTTY_FMT_UPPER_EXP), "1.23456789E3 s");
}

TEST_F(FormattingTest, FormatUpperExpFourDecimalPlaces) {
  Second s(1234.56789);
  EXPECT_EQ(s.format(4, QTTY_FMT_UPPER_EXP), "1.2346E3 s");
}

TEST_F(FormattingTest, FormatNegativeValue) {
  Meter m(-42.5);
  EXPECT_EQ(m.format(), "-42.5 m");
  EXPECT_EQ(m.format(1), "-42.5 m");
  EXPECT_EQ(m.format(2, QTTY_FMT_LOWER_EXP), "-4.25e1 m");
}

TEST_F(FormattingTest, FormatZeroValue) {
  Second s(0.0);
  EXPECT_EQ(s.format(), "0 s");
  EXPECT_EQ(s.format(2), "0.00 s");
}

TEST_F(FormattingTest, FormatMeterDefault) {
  Meter m(42.0);
  EXPECT_EQ(m.format(), "42 m");
}

TEST_F(FormattingTest, FormatKilometerDefault) {
  Kilometer km(1.5);
  EXPECT_EQ(km.format(), "1.5 km");
}

TEST_F(FormattingTest, FormatLargeValue) {
  Meter m(1.5e12);
  EXPECT_EQ(m.format(2, QTTY_FMT_LOWER_EXP), "1.50e12 m");
}

// Verify format() with precision=2 matches operator<< with fixed+setprecision(2).
TEST_F(FormattingTest, FormatMatchesStream) {
  Second s(1234.56789);
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << s;
  EXPECT_EQ(s.format(2), oss.str());
}
