//
// Created by Amrit Rathie on 2019-05-15.
//

#include "mod.h"

const int signed_mod(const int x, const int n){
return ((x % n) + n) %
n;
}
