#include <header.hpp>

int main(int argc, char *argv[]) {
    boost::filesystem::path pth_to_file = ".";
    if (argc > 1)
    {
        pth_to_file = argv[1];
    }

    if (!exists(pth_to_file))
    {
        throw exception();
    }


    return 0;
}