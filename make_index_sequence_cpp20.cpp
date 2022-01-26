template<class T, T ... indexes> requires(std::is_integral_v<T>)
class IntegerSequence {   };

template<size_t ... indexes>
using index_sequence = IntegerSequence<size_t, indexes...>;

template<class T, size_t N, size_t ... indexes> requires(std::is_integral_v<T>)
auto make_integer_sequence_helper(){
    if constexpr (N == 0) return index_sequence<indexes...>{};
    else return make_integer_sequence_helper<T, N-1, 0, indexes+1 ...>();
}

template<class T, size_t N> requires(std::is_integral_v<T>)
auto make_integer_sequence(){
    return make_integer_sequence_helper<T, N-1,0>();
}

template<size_t ... indexes>
auto make_index_sequence(){return make_integer_sequence<size_t, indexes...>();}

template <class... T, size_t... indexes>
void print_tuple(std::tuple<T...> const& t, index_sequence<indexes...>) {
    (print(std::get<indexes>(t)), ...);
}


int main() {
    auto t = std::tuple{1, 2, std::string{"hello"}};
    print_tuple(t, make_index_sequence<3>());
}
