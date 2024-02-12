#pragma once

class file;
class file_manager;

class folder
{
public:
    folder(std::filesystem::path  folder_path = "");

    file get_file(const std::filesystem::path& file_path) const;
    folder get_folder(const std::filesystem::path& folder_path) const;
    std::filesystem::path get_path() const;

private:
    friend class file_manager;
    file_manager* m_file_manager;

    bool m_is_project_file;

    std::filesystem::path m_folder_path;
};