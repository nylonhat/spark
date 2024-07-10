#ifndef RANGE_FORMATTER_H
#define RANGE_FORMATTER_H

#include <format>
#include <utility>

template<std::ranges::input_range R>
struct std::formatter<R>{
	using T = remove_cvref_t<std::ranges::range_reference_t<R>>;
	std::formatter<T> element_formatter;

	constexpr auto parse(auto& context){
		return element_formatter.parse(context);
	}

	auto format(const R& range, auto& context) const {
		return format_impl(range, context);
	}

	auto format_impl(auto&& range, auto& context) const {
		auto out = context.out();
		std::string delimiter = "[";
		for(auto&& element : range){
			out = std::format_to(out, "{}", std::exchange(delimiter, ", "));
			context.advance_to(out);
			out = element_formatter.format(element, context);
		}

		return std::format_to(out, "]");
	}
};



#endif
