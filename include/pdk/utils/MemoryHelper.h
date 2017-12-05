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
// Created by softboy on 2017/12/04.

#ifndef PDK_UTILS_MEMORY_HELPER_H
#define PDK_UTILS_MEMORY_HELPER_H

#include "pdk/global/Global.h"

namespace pdk {
namespace utils {

struct CalculateGrowingBlockSizeResult
{
   size_t m_size;
   size_t m_elementCount;
};

size_t PDK_CORE_EXPORT PDK_DECL_CONST_FUNCTION
calculate_block_size(size_t elementCount, size_t elementSize, size_t headerSize = 0) noexcept;

CalculateGrowingBlockSizeResult PDK_CORE_EXPORT PDK_DECL_CONST_FUNCTION
calculate_growing_block_size(size_t elementCount, size_t elementSize, size_t headerSize = 0) noexcept;

} // utils
} // pdk

#endif // PDK_UTILS_MEMORY_HELPER_H