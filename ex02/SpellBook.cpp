# include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() 
{
    for(std::map<std::string, ASpell*> :: iterator  it = arr_spell.begin(); it != arr_spell.end(); ++it)
    {
        delete it->second;
    }    
    arr_spell.clear();
}

void SpellBook::learnSpell(ASpell *aspell_ptr) 
{
    if(aspell_ptr)
        arr_spell.insert(std::pair<std::string, ASpell*>(aspell_ptr->getName(), aspell_ptr->clone()));
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell*> :: iterator  it = arr_spell.find(spell_name);
    if( it != arr_spell.end())
    {
        delete it->second;
    }
    arr_spell.erase(spell_name);
}
       
ASpell *SpellBook::createSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell*> :: iterator  it = arr_spell.find(spell_name);
    if( it != arr_spell.end())
    {
        return arr_spell[spell_name];
    }
    return NULL;
}
