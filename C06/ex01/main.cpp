#include <iostream>
#include "Serializer.hpp"

int main(void)
{
    Data data;

    data.name = "Zakaria";
    data.login_intra = "zouazrou";
    data.level = 5.33f;

    std::cout << "Data address: " << &data << ", login-intra : " << data.login_intra << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t)(dec): " << raw << std::endl;
    std::cout << "Serialized Data (uintptr_t)(hex): " << std::hex << raw << std::dec << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedData << ", login-intra = " << deserializedData->login_intra << std::endl;

    return 0;
}