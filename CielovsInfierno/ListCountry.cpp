#include <structs.h>
void ListCountry::addCountry(QString name){
    countries.append(new Country(name));
}


void ListCountry::addActions(QString nameCountry, int sin, int good){
    for(int i = 0; i<countries.length(); i++){
        if(countries.at(i)->name == nameCountry){
            countries.at(i)->totalGoods += good;
            countries.at(i)->totalSins += sin;
        }
    }
}

Country* ListCountry::getMax(){
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

Country* ListCountry::getMaxSin(){
    int max = 0;
    Country* maxCountry;

    for(int i = 0; i<countries.length(); i++){
        if(countries.at(i)->totalSins > max){
            if(!countries.at(i)->taken){
                maxCountry = countries.at(i);
                max = countries.at(i)->totalGoods;
            }
        }
    }
    maxCountry->taken = true;
    return maxCountry;
}

Country* ListCountry::getMinSin(){
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

Country* ListCountry::getMin(){
    int min = 20000;
    Country* minCountry;
    for(int i = 0; i<countries.length(); i++){
        if(countries.at(i)->totalGoods < min){
            if(!countries.at(i)->takenLess){
                minCountry = countries.at(i);
                min = countries.at(i)->totalGoods;
            }
        }
    }
    minCountry->takenLess = true;
    return minCountry;
}

ListCountry* ListCountry::getTopTen(){
    ListCountry* topList = new ListCountry();
    for(int i = 0; i < 10; i++){
        topList->countries.append(getMax());
    }
    return topList;
}

ListCountry* ListCountry::getLastFive(){
    ListCountry* lastList = new ListCountry();
    for(int i = 0; i < 5; i++){
        lastList->countries.append(getMin());
    }
    return lastList;
}

ListCountry* ListCountry::getTopTenSinners(){
    ListCountry* topList = new ListCountry();
    for(int i = 0; i < 10; i++){
        topList->countries.append(getMaxSin());
    }
    return topList;
}

ListCountry* ListCountry::getLastFiveSinners(){
    ListCountry* lastList = new ListCountry();
    for(int i = 0; i < 5; i++){
        lastList->countries.append(getMinSin());
    }
    return lastList;
}


