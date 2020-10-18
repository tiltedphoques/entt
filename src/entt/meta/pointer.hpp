#ifndef ENTT_META_POINTER_HPP
#define ENTT_META_POINTER_HPP

#include <memory>
#include <type_traits>
#include "type_traits.hpp"


namespace entt {


/**
 * @brief Makes plain pointers pointer-like types for the meta system.
 * @tparam Type Element type.
 */
template<typename Type>
struct is_meta_pointer_like<Type *>
        : std::true_type
{};


/**
 * @brief Makes `std::shared_ptr`s of any type pointer-like types for the meta
 * system.
 * @tparam Type Element type.
 */
template<typename Type>
struct is_meta_pointer_like<std::shared_ptr<Type>>
        : std::true_type
{};


/**
 * @brief Makes `std::unique_ptr`s of any type pointer-like types for the meta
 * system.
 * @tparam Type Element type.
 * @tparam Args Other arguments.
 */
template<typename Type, typename... Args>
struct is_meta_pointer_like<std::unique_ptr<Type, Args...>>
        : std::true_type
{};


}


#endif
