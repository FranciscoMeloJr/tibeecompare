/* Copyright (c) 2014 Francois Doray <francois.pierre-doray@polymtl.ca>
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
#include "server/handlers/HandleGetProperties.hpp"

#include "base/print.hpp"

namespace tibee
{
namespace server
{
namespace handlers
{

namespace
{

using base::tberror;
using base::tbendl;

}  // namespace

bool HandleGetProperties(mq::MessageDecoder* request,
                         mq::MessageEncoder* response)
{
    return true;
}

}  // namespace handlers
}  // namespace server
}  // namespace tibee
