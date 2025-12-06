#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : AForm(s), target(s.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& s)
{
    if (this != &s)
    {
        this->target = s.target;
        AForm::operator=(s);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// ****

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    std::string fileName = "_shrubbery";
    if (this->getIsSign() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > 137)
        throw GradeTooLowException();
    // **Form's Action**
    fileName = target + fileName;
    std::ofstream myFile(fileName.c_str());
    myFile << 
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⠟⠻⢶⣀⣠⣽⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣠⡀⠀⠀⠀⢿⣅⠀⠀⠀⠀⠉⠉⠹⣧⠀⠀⣀⣀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠟⠉⠉⠛⣷⡤⠴⢾⣁⡀⠀⠀⠀⠀⠀⠀⠹⡧⠛⠉⠛⠛⢷⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣧⠀⠀⠀⠀⠀⠉⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠈⢻⣆⣤⣀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⡟⢹⣧⣀⡄⢀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⢀⣠⡴⠟⠈⠉⠙⠷⠶⣶⣆⠀⣠⣽⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣠⣤⣤⠶⣶⡟⢁⣼⠁⠉⠓⠚⠉⣿⣀⠀⠀⠀⠀⠀⠀⠀\n"
        "⢀⣾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠈⠛⠚⠁⠀⠀⠀⠀⠀⠀⣀⠀⠀⢀⡼⠋⠀⠀⠁⠀⠀⠀⠙⠉⠀⠀⠀⠀⠀⠀⢀⡽⠀⠀⠀⠀⠀⠀⠀\n"
        "⢾⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⢸⣳⣼⣿⢠⣰⡟⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⢴⣖⠀⠀⠀⠀⠀\n"
        "⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠋⠿⢾⡆⠀⢳⣿⠈⡷⢯⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀⠀⠀\n"
        "⢸⣿⡀⠀⢀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣾⠿⡄⢀⠎⢘⠛⡿⢧⣤⣤⣦⠄⠀⣤⡄⠀⠀⠀⠀⢠⣤⢤⡤⣞⡥⣶⣄⣀⠀⠀\n"
        "⠀⠸⣷⣤⣾⣷⣀⣀⣿⣷⣠⣴⣤⡀⠀⠐⠒⠋⠀⠈⠳⣷⢤⡀⡎⢸⠁⠀⠈⡇⡍⠀⢠⣷⣷⣂⡤⠄⠀⠈⠛⠳⠷⠟⠀⠀⠀⠘⠋⣿\n"
        "⠀⠀⠀⠀⠀⠈⠛⢿⣯⡉⠉⣠⠏⠀⠐⣶⠆⠀⢀⣠⣤⡌⢲⠙⠃⣾⠀⠀⡼⣰⠓⢊⣡⠷⢯⡑⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿\n"
        "⠀⠀⠀⠀⢀⣀⣠⡼⠉⠙⠷⠃⠀⠀⡴⢡⠔⠚⠉⠀⠘⣿⡠⠖⢻⢮⠀⠀⠀⠀⣾⣩⣀⣄⣀⡱⠘⠓⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸\n"
        "⠀⠀⠀⠰⡿⠍⠁⠀⠀⠀⠀⠀⠀⠈⠴⠃⠀⠀⠀⠀⠀⠈⠀⠀⠀⢛⡆⢸⢨⠞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡴⠉\n"
        "⠀⠀⠀⠀⣧⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⣠⠞⠁⠃⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢴⣶⢞⠛⠛⠃⠀⠀\n"
        "⠀⠀⠀⠀⠈⠙⠛⣷⣠⠀⠀⠀⢀⣷⣀⠀⠀⠀⠀⢠⣤⠾⠚⠛⣧⠀⠀⢀⡼⢦⣴⠛⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢛⡿⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠈⠿⠷⠶⠾⠻⡭⠟⠀⠀⠀⠀⢠⣉⣷⠀⠀⡏⠀⠀⣞⠀⠀⠀⠸⣏⡀⠀⠀⠀⠀⠀⠀⡶⠶⠶⠒⠾⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⠴⠶⠴⠴⠷⠾⠉⠁⠀⢠⡇⠀⠀⢸⠀⠀⠀⠀⠈⠙⠛⣦⣠⠤⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣇⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
        "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠋⠀⠀⠀⠳⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
    myFile.close();
}
