# include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout<< this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout<< this->name << ": My job here is done!" << std::endl;
    for(std::map < std::string, ASpell *> :: iterator it = spell_arr.begin(); it != spell_arr.end(); ++it )
        delete it->second;
    spell_arr.clear();    
}

std::string const &Warlock::getName() const { return(this->name);}
std::string const &Warlock::getTitle() const {return(this->title);}  

void Warlock::setTitle(std::string const &title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout<< this->name << ": I am "<< this->name << ", "<< this->title << "!\n";
}

void Warlock::learnSpell(ASpell *aspell_ptr) 
{
    if(aspell_ptr)
        spell_arr.insert(std::pair<std::string, ASpell *>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell *> :: iterator it = spell_arr.find(name);

    if( it != spell_arr.end())
    {
        delete it->second;
        it->second = 0;
    }
    spell_arr.erase(name);
}

void Warlock::launchSpell(std::string name, ATarget const &atarget_ref)
{
    ASpell * spell = spell_arr[name];

    if(spell)
        spell->launch(atarget_ref);
}