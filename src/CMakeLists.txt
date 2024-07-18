# CMakeList.txt: проект CMake для bank_branch; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

project ("bank_branch")
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
include_directories("C:/Users/Александр/Desktop/учеба/Методы программирования/bank_branch/incude/rapidjson")

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# Добавьте источник в исполняемый файл этого проекта.
add_executable (bank_branch "main.cpp" "json_reader.h" "json_reader.cpp" "output_writer.h" "output_writer.cpp" "bank_branch.h" "bank_branch.cpp" "incude/rapidjson/allocators.h" "incude/rapidjson/cursorstreamwrapper.h" "incude/rapidjson/document.h" "incude/rapidjson/encodedstream.h" "incude/rapidjson/encodings.h" "incude/rapidjson/filereadstream.h" "incude/rapidjson/filewritestream.h" "incude/rapidjson/fwd.h" "incude/rapidjson/istreamwrapper.h" "incude/rapidjson/memorybuffer.h" "incude/rapidjson/memorystream.h" "incude/rapidjson/ostreamwrapper.h" "incude/rapidjson/pointer.h" "incude/rapidjson/prettywriter.h" "incude/rapidjson/rapidjson.h" "incude/rapidjson/reader.h" "incude/rapidjson/schema.h" "incude/rapidjson/stream.h" "incude/rapidjson/stringbuffer.h" "incude/rapidjson/uri.h" "incude/rapidjson/writer.h" "incude/rapidjson/error/en.h" "incude/rapidjson/error/error.h" "incude/rapidjson/internal/biginteger.h" "incude/rapidjson/internal/clzll.h" "incude/rapidjson/internal/diyfp.h" "incude/rapidjson/internal/dtoa.h" "incude/rapidjson/internal/ieee754.h" "incude/rapidjson/internal/itoa.h" "incude/rapidjson/internal/meta.h" "incude/rapidjson/internal/pow10.h" "incude/rapidjson/internal/regex.h" "incude/rapidjson/internal/stack.h" "incude/rapidjson/internal/strfunc.h" "incude/rapidjson/internal/strtod.h" "incude/rapidjson/internal/swap.h" "incude/rapidjson/msinttypes/inttypes.h" "incude/rapidjson/msinttypes/stdint.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bank_branch PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
