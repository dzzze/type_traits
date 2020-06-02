#pragma once

#include <type_traits>

// https://en.cppreference.com/w/cpp/experimental/is_detected

namespace dze {

struct nonesuch
{
    ~nonesuch() = delete;
    nonesuch(const nonesuch&) = delete;
    void operator=(const nonesuch&) = delete;
};

namespace details {

template <
    typename Default,
    typename AlwaysVoid,
    template <typename...> typename Trait,
    typename... Args>
struct detector
{
    using value_t = std::false_type;
    using type = Default;
};

template <typename Default, template <typename...> typename Trait, typename... Args>
struct detector<Default, std::void_t<Trait<Args...>>, Trait, Args...>
{
    using value_t = std::true_type;
    using type = Trait<Args...>;
};

} // namespace details

template <template <typename...> typename Trait, typename... Args>
using is_detected = typename details::detector<nonesuch, void, Trait, Args...>::value_t;

template <template <typename...> typename Trait, typename... Args>
inline constexpr bool is_detected_v = is_detected<Trait, Args...>::value;

template <template <typename...> typename Trait, typename... Args>
using detected_t = typename details::detector<nonesuch, void, Trait, Args...>::type;

template <typename Expected, template <typename...> typename Trait, typename... Args>
using is_detected_exact = std::is_same<Expected, detected_t<Trait, Args...>>;

template <typename Expected, template <typename...> typename Trait, typename... Args>
inline constexpr bool is_detected_exact_v =
    is_detected_exact<Expected, Trait, Args...>::value;

} // namespace dze
