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
#ifndef _TIBEE_CRITICAL_SEGMENT_HPP
#define _TIBEE_CRITICAL_SEGMENT_HPP

#include <vector>

#include "base/BasicTypes.hpp"

namespace tibee
{
namespace critical
{

class Segment
{
public:
    Segment()
        : _thread(-1), _startTs(0), _endTs(0), _isCritical(true) {}

    Segment(thread_t thread, timestamp_t startTs, timestamp_t endTs, bool isCritical)
        : _thread(thread), _startTs(startTs), _endTs(endTs), _isCritical(isCritical) {}

    thread_t thread() const { return _thread; }
    void set_thread(thread_t thread) { _thread = thread; }

    timestamp_t startTs() const { return _startTs; }
    void set_startTs(timestamp_t startTs) { _startTs = startTs; }

    timestamp_t endTs() const { return _endTs; }
    void set_endTs(timestamp_t endTs) { _endTs = endTs; }

    bool critical() const { return _isCritical; }
    void set_critical(bool isCritical) { _isCritical = isCritical; }

    bool operator==(const Segment& other) const {
        return _thread == other._thread &&
            _startTs == other._startTs &&
            _endTs == other._endTs &&
            _isCritical == other._isCritical;
    }

    bool operator<(const Segment& other) const {
        if (_startTs < other._startTs)
            return true;
        if (_startTs > other._startTs)
            return false;
        if (_endTs < other._endTs)
            return true;
        if (_endTs > other._endTs)
            return false;
        if (_thread < other._thread)
            return true;
        if (_thread > other._thread)
            return false;
        return _isCritical < other._isCritical;
    }

private:
    // Thread.
    thread_t _thread;

    // Start timestamp.
    timestamp_t _startTs;

    // End timestamp.
    timestamp_t _endTs;

    // Indicates whether the segment is on the critical path.
    bool _isCritical;
};

typedef std::vector<Segment> Segments;

}  // namespace critical
}  // namespace tibee

#endif // _TIBEE_CRITICAL_SEGMENT_HPP