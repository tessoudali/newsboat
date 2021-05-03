#ifndef NEWSBOAT_FILESYSTEMBROWSER_H
#define NEWSBOAT_FILESYSTEMBROWSER_H

#include <string>
#include <sys/stat.h>

#include "3rd-party/optional.hpp"

namespace newsboat {

namespace FileSystemBrowser {

enum class FileType {
	Unknown,
	RegularFile,
	Directory,
	BlockDevice,
	CharDevice,
	Fifo,
	Symlink,
	Socket,
};

FileType mode_to_filetype(mode_t mode);

/// Convert the filetype into an ASCII character that `ls` and others use to
/// represent it.
///
/// \note `Unknown` filetype is represented by a question mark.
char filetype_to_char(FileType type);

/// Get a suffix that `ls --classify` adds to names with given `mode`.
nonstd::optional<char> mode_suffix(mode_t mode);

/// An entry in a listing, e.g. a file, a directory or suchlike.
struct FileSystemEntry {
	FileType filetype;
	std::string name;
};

/// The name of the user with a given UID, padded on the right to the width of
/// 8 characters. If the name is unknown, returns 8 question marks.
std::string get_user_padded(uid_t uid);

/// The name of the group with a given GID, padded on the right to the width of
/// 8 characters. If the name is unknown, returns 8 question marks.
std::string get_group_padded(gid_t gid);

} // namespace FileSystemBrowser

} // namespace newsboat

#endif //NEWSBOAT_FILESYSTEMBROWSER_H
