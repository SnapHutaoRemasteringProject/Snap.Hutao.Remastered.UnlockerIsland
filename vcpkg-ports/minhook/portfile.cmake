vcpkg_check_linkage(ONLY_STATIC_LIBRARY ONLY_DYNAMIC_CRT)

vcpkg_from_git(
    OUT_SOURCE_PATH SOURCE_PATH
    URL "https://github.com/TsudaKageyu/minhook.git"
    REF "c3fcafdc10146beb5919319d0683e44e3c30d537"
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS
        -DBUILD_SHARED_LIBS=OFF
)

vcpkg_cmake_install()
vcpkg_copy_pdbs()

file(REMOVE_RECURSE
    "${CURRENT_PACKAGES_DIR}/debug/include"
    "${CURRENT_PACKAGES_DIR}/debug/lib/minhook"
    "${CURRENT_PACKAGES_DIR}/lib/minhook"
    "${CURRENT_PACKAGES_DIR}/share/minhook"
)

vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSE.txt")
