template <class T, class... Ts>
requires(sizeof...(Ts) > 0 &&
         std::is_same_v<std::common_type_t<Ts...>, T>) constexpr T
    max(T arg, Ts... args) {
    if constexpr (sizeof...(Ts) == 1)
        return std::max(arg, args...);
    else
        return max(arg, max<Ts...>(args...));
}
