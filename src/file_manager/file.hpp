#pragma once

class file_manager;

class file
{
public:
    file(std::filesystem::path  file_path = "");
    file& operator=(const file& other);
    operator std::filesystem::path();
    operator std::filesystem::path&();

    file copy(const std::filesystem::path& new_path);
    [[nodiscard]] bool exists() const;
    [[nodiscard]] std::filesystem::path get_path() const;
    [[nodiscard]] file move(std::filesystem::path new_path) const;

private:
    friend class file_manager;

    bool m_is_project_file;
    std::filesystem::path m_file_path;
};