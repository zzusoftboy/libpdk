// @copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2018/01/22.

#ifndef PDK_STDEXT_TYPE_TRAITS_CALLABLE_IFNO_TRAITS_H
#define PDK_STDEXT_TYPE_TRAITS_CALLABLE_IFNO_TRAITS_H

#include <type_traits>

namespace pdk {
namespace stdext {

template <typename CallableType>
struct CallableInfoTrait
{
   constexpr static bool isMemberCallable = false;
};

template <typename RetType, typename ...ParamTypes>
struct CallableInfoTrait<RetType (&)(ParamTypes ...args)>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = false;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename ...ParamTypes>
struct CallableInfoTrait<RetType (*)(ParamTypes ...args)>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = false;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename ...ParamTypes>
struct CallableInfoTrait<RetType (ParamTypes ...args)>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = false;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename ...ParamTypes>
struct CallableInfoTrait<RetType (&)(ParamTypes ...args, ...)>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = false;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename ...ParamTypes>
struct CallableInfoTrait<RetType (*)(ParamTypes ...args, ...)>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = false;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename ...ParamTypes>
struct CallableInfoTrait<RetType (ParamTypes ...args, ...)>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = false;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args)>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...)>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) const>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) const>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) volatile>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) volatile>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) const volatile>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) const volatile>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) &>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) &>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) const&>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) const&>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) volatile&>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) volatile&>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) const volatile&>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) const volatile&>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) &&>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) &&>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) const&&>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) const&&>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) volatile&&>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) volatile&&>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args) const volatile&&>
{
   using Signature = RetType(ParamTypes ...args);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = false;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

template <typename RetType, typename Class, typename ...ParamTypes>
struct CallableInfoTrait<RetType (Class::*)(ParamTypes... args, ...) const volatile&&>
{
   using Signature = RetType(ParamTypes ...args, ...);
   using ReturnType = RetType;
   constexpr static size_t argNum = sizeof...(ParamTypes);
   constexpr static bool hasVaridicParams = true;
   constexpr static bool hasParamDef = argNum != 0 || hasVaridicParams;
   constexpr static bool isMemberCallable = true;
   constexpr static bool hasReturn = !std::is_same<RetType, void>::value;
   template <size_t index>
   struct arg
   {
      using type = typename std::tuple_element<index, std::tuple<ParamTypes...>>::type;
   };
};

} // stdext
} // pdk

#endif // PDK_STDEXT_TYPE_TRAITS_CALLABLE_IFNO_TRAITS_H
