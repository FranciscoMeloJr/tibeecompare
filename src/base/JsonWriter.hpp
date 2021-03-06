/* Copyright (c) 2015 Francois Pierre Doray <francois.pierre-doray@polymtl.ca>
 *
 * This file is part of tibeecompare.
 *
 * tibeecompare is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tibeecompare is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tibeecompare.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _TIBEE_BASE_JSONWRITER_HPP
#define _TIBEE_BASE_JSONWRITER_HPP

#include <boost/filesystem.hpp>
#include <fstream>
#include <stack>

#include "base/BasicTypes.hpp"

namespace tibee
{
namespace base
{

/**
 * Json file writer.
 *
 * @author Francois Doray
 */
class JsonWriter
{
public:
    JsonWriter();
    ~JsonWriter();

    bool Open(const boost::filesystem::path& path);

    // Array.
    void BeginArray();
    void EndArray();
    void Value(const std::string& value);

    template<typename T>
    void Value(const T& value)
    {
        EnsureFile();
        ValueInternal(std::to_string(value));
    }

    // Dictionary.
    void BeginDict();
    void EndDict();
    void KeyValue(const std::string& key, const std::string& value);

    template<typename T>
    void KeyValue(const std::string& key, const T& value)
    {
        EnsureFile();
        KeyValueInternal(key, std::to_string(value));
    }

    void KeyDictValue(const std::string& key);
    void KeyArrayValue(const std::string& key);

    size_t sec() { return _sections.size(); }

private:
    void EnsureFile();

    void ValueInternal(const std::string& escapedValue);
    void KeyValueInternal(const std::string& key,
                          const std::string& escapedValue);

    // File stream.
    std::ofstream _out;

    // Sanity checks.
    enum class SectionType { kArray, kDict };
    std::stack<SectionType> _sections;
    std::stack<bool> _isFirstOfSection;
};

}  // namespace base
}  // namespace tibee

#endif // _TIBEE_BASE_JSONWRITER_HPP
