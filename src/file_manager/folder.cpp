#include "folder.hpp"

#include <utility>
#include "common.hpp"
#include "file_manager.hpp"

folder::folder(std::filesystem::path folder_path) :
    m_file_manager(nullptr), m_is_project_file(false),
    m_folder_path(std::move(folder_path))
{
}

file folder::get_file(const std::filesystem::path& file_path) const
{
    if (file_path.is_absolute())
        throw std::invalid_argument("folder#get_file requires a relative path.");
    if (file_path.string().contains(".."))
        throw std::invalid_argument("Relative path traversal is not allowed, refrain from using \"..\" in file paths.");

    return {m_folder_path / file_path};
}

folder folder::get_folder(const std::filesystem::path& folder_path) const
{
    if (folder_path.is_absolute())
        throw std::invalid_argument("folder#get_folder requires a relative path.");
    if (folder_path.string().contains(".."))
        throw std::invalid_argument("Relative path traversal is not allowed, refrain from using \"..\" in file paths.");
    return {m_folder_path / folder_path};
}

std::filesystem::path folder::get_path() const
{
    return m_folder_path;
}
