#pragma once

#include <Siv3D.hpp>

namespace s3d {
	namespace SimpleGUI {
		inline constexpr ColorF GetTextColor(bool enabled) noexcept
		{
			return (enabled ? ColorF(0.11) : ColorF(0.67));
		}
		/// @brief テキストボックスを表示します。
		/// @param text テキストボックスの状態への参照
		/// @param pos テキストボックスの左上の座標
		/// @param size テキストボックスの幅と高さ（ピクセル）
		/// @param maxChars 入力できる最大の文字数 (char32 の要素数）
		/// @param enabled テキストボックスの操作を有効にするか
		/// @return テキストが操作された場合 true, それ以外の場合は false
		bool TextBoxMultipleLines(TextEditState& text, const Point& pos, const Point& size, const Optional<size_t>& maxChars = unspecified, bool enabled = true);

		/// @brief テキストボックスを表示します。
		/// @param text テキストボックスの状態への参照
		/// @param pos テキストボックスの中心座標
		/// @param size テキストボックスの幅と高さ（ピクセル）
		/// @param maxChars 入力できる最大の文字数 (char32 の要素数）
		/// @param enabled テキストボックスの操作を有効にするか
		/// @return テキストが操作された場合 true, それ以外の場合は false
		bool TextBoxMultipleLinesAt(TextEditState& text, const Point& center, const Point& size, const Optional<size_t>& maxChars = unspecified, bool enabled = true);
	}
}
