#include <structs.h>

void CountryList::addCountry(QString name){
    countries.append(new Country(name));
}


void CountryList::addActions(QString nameCountry, int sin, int good){
    for(int i = 0; i<countries.length(); i++){
        if(countries.at(i)->name == nameCountry){
            countries.at(i)->totalGoods += good;
            countries.at(i)->totalSins += sin;
        }
    }
}

Country* CountryList::getMax(){
    int max = 0;
    Country* maxCountry;

    for(int i = 0; i<countries.length(); i++){
        if(countries.at(i)->totalGoods > max){
            if(!countries.at(i)->taken){
                maxCountry = countries.at(i);
                max = countries.at(i)->totalGoods;
            }
        }
    }
    maxCountry->taken = true;
    return maxCountry;
}

Country* CountryList::getMin(){
    int min = 20000;
    Country* minCountry;
    for(int i = 0; i<countries.length(); i++){
        if(countries.at(i)->totalSins < min){
            if(!countries.at(i)->takenLess){
                minCountry = countries.at(i);
                min = countries.at(i)->totalGoods;
            }
        }
    }
    minCountry->takenLess = true;
    return minCountry;
}

CountryList* CountryList::getTopTen(){
    CountryList* topList = new CountryList();
    for(int i = 0; i < 10; i++){
        topList->countries.append(getMax());
    }
    return topList;
}

CountryList* CountryList::getLastFive(){
    CountryList* lastList = new CountryList();
    for(int i = 0; i < 5; i++){
        lastList->countries.append(getMin());
    }
    return lastList;
}
