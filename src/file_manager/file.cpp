#include "file.hpp"

#include <utility>
#include "common.hpp"
#include "file_manager.hpp"

file::file(std::filesystem::path file_path) :
    m_is_project_file(false),
    m_file_path(std::move(file_path))
{
}

file& file::operator=(const file& other)
{
    m_file_path = other.m_file_path;
    return *this;
}

file::operator std::filesystem::path()
{
    return m_file_path;
}

file::operator std::filesystem::path&()
{
    return m_file_path;
}

bool file::exists() const
{
    return std::filesystem::exists(m_file_path);
}

std::filesystem::path file::get_path() const
{
    return m_file_path;
}

file file::move(std::filesystem::path new_path) const
{
    if (new_path.is_relative())
        new_path = m_file_path.parent_path() / new_path;

    file_manager::ensure_file_can_be_created(new_path);

    if (std::filesystem::exists(m_file_path))
        std::filesystem::rename(m_file_path, new_path);

    return {new_path};
}
