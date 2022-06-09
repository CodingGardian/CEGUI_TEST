// TODO: Create utility for std::function (how the heck does the commitee do this?)

#include <functional>

namespace CEGUI {
    namespace UTIL {
        template<typename T>
        struct STLFUNC;

        template<typename Ret, typename... Args>
        struct STLFUNC<std::function<Ret(Args...)>> {
            static const size_t nargs = sizeof...(Args);

            typedef Ret ReturnType;

            template<size_t i>
            struct param {
                typedef std::tuple<Args...> params;
                typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
            };
        };
    };
};