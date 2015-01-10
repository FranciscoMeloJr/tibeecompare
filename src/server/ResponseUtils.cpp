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
#include "server/ResponseUtils.hpp"

namespace tibee
{
namespace server
{

void WriteNodeToResponse(int64_t beginTime,
                         int64_t duration,
                         int64_t extraDuration,
                         int32_t matchCode,
                         quark::Quark typeQuark,
                         int32_t tid,
                         int32_t stackDepth,
                         int32_t parentNodeId,
                         int32_t childIndex,
                         mq::MessageEncoder* response)
{
    response->Write(beginTime);
    response->Write(duration);
    response->Write(extraDuration);
    response->Write(matchCode);
    response->Write(static_cast<int32_t>(typeQuark.get()));
    response->Write(tid);
    response->Write(stackDepth);
    response->Write(parentNodeId);
    response->Write(childIndex);
}

}  // namespace server
}  // namespace tibee
