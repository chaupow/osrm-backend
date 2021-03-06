#ifndef OSMIUM_OSM_TYPES_HPP
#define OSMIUM_OSM_TYPES_HPP

/*

This file is part of Osmium (http://osmcode.org/libosmium).

Copyright 2013-2015 Jochen Topf <jochen@topf.org> and others (see README).

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <cstdint>
#include <cstdlib>

namespace osmium {

    /*
     * The following typedefs are chosen so that they can represent all needed
     * numbers and still be reasonably space efficient. As the OSM database
     * needs 64 bit IDs for nodes, this size is used for all object IDs.
     */
    typedef int64_t  object_id_type;          ///< Type for OSM object (node, way, or relation) IDs.
    typedef uint64_t unsigned_object_id_type; ///< Type for OSM object (node, way, or relation) IDs where we only allow positive IDs.
    typedef uint32_t object_version_type;     ///< Type for OSM object version number.
    typedef uint32_t changeset_id_type;       ///< Type for OSM changeset IDs.
    typedef uint32_t user_id_type;            ///< Type for OSM user IDs.
    typedef int32_t  signed_user_id_type;     ///< Type for signed OSM user IDs.
    typedef uint32_t num_changes_type;        ///< Type for changeset num_changes.

    /**
     * Size for strings in OSM data such as user names, tag keys, roles, etc.
     * In Osmium they can be up to 2^16 bytes long, but OSM usually has lower
     * defined limits.
     */
    typedef uint16_t string_size_type;

    inline object_id_type string_to_object_id(const char* string) {
        return std::atoll(string);
    }

    inline object_version_type string_to_object_version(const char* string) {
        return static_cast<object_version_type>(std::atol(string));
    }

    inline changeset_id_type string_to_changeset_id(const char* string) {
        return static_cast<changeset_id_type>(std::atol(string));
    }

    inline signed_user_id_type string_to_user_id(const char* string) {
        return static_cast<signed_user_id_type>(std::atol(string));
    }

    inline num_changes_type string_to_num_changes(const char* string) {
        return static_cast<num_changes_type>(std::atol(string));
    }

} // namespace osmium

#endif // OSMIUM_OSM_TYPES_HPP
