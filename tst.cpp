#include <iostream>
#include <ctime>

void displayTimestamp()
{
    std::time_t now = std::time(NULL);
    std::tm *tm = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, 20, "[%Y%m%d_%H%M%S]", tm);
    std::cout << buffer << std::endl;
    std::cout << '[' << tm->tm_year << "'" << tm->tm_mon<< "'"  << tm->tm_yday << "_"<< tm->tm_hour << tm->tm_min << tm->tm_sec << ']' << std::endl;
}

int main()
{
    displayTimestamp();
}
