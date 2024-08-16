#ifndef PKG_MANAGER_H
#define PKG_MANAGER_H

void install_package(const char *package_file);
void uninstall_package(const char *package_name);
void list_installed_packages(void);

#endif
