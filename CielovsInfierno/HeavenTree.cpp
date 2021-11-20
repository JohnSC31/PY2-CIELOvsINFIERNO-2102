#include "structs.h"
#include <algorithm>

int HeavenTree::height(HeavenNode *t){
    int h = 0;
    if(t != NULL){
        int leftHeight = height(t->leftChild);
        int rightHeight = height(t->rightChild);
        int maxHeight = maxInt(leftHeight, rightHeight);
        h = maxHeight + 1;
    }
    return h;
}

int HeavenTree::difference(HeavenNode *t){
    int leftHeight = height(t->leftChild);
    int rightHeight = height(t->rightChild);
    int bFactor = leftHeight - rightHeight;
    return bFactor;
}

HeavenNode* HeavenTree::rrRot(HeavenNode *parent){
    HeavenNode* t;
    t = parent->rightChild;
    parent->rightChild = t->leftChild;
    t->leftChild = parent;
    //qDebug() << "rr";
    return t;
}

HeavenNode* HeavenTree::llRot(HeavenNode *parent){
    HeavenNode* t;
    t = parent->leftChild;
    parent->leftChild = t->rightChild;
    t->rightChild = parent;
    return t;
}

HeavenNode* HeavenTree::lrRot(HeavenNode *parent){
    HeavenNode* t;
    t = parent->leftChild;
    parent->leftChild = rrRot(t);
    return llRot(parent);
}

HeavenNode* HeavenTree::rlRot(HeavenNode *parent){
    HeavenNode* t;
    t = parent->rightChild;
    parent->rightChild = llRot(t);
    return rrRot(parent);
}

HeavenNode* HeavenTree::balance(HeavenNode *t){
    int balFactor = difference(t);
    if(balFactor > 1){
        if(difference(t->leftChild) > 0)
            t = llRot(t);
        else
            t = lrRot(t);
    }
    else if(balFactor < -1){
        if(difference(t->rightChild) > 0)
            t = rlRot(t);
        else
            t = rrRot(t);
    }
    return t;
}

HeavenNode* HeavenTree::insert(HeavenNode *r, Human *theHuman){
    if(r == 0){
        r = new HeavenNode(theHuman);
        r->leftChild = 0;
        r->rightChild = 0;
        return r;
    }
    else if(theHuman->id < r->human->id){
        r->leftChild = insert(r->leftChild, theHuman);
        r = balance(r);
    }
    else if(theHuman->id >= r->human->id){
        r->rightChild = insert(r->rightChild, theHuman);
    }
    return r;
}


void HeavenTree::show(HeavenNode *p, int l){
    int i;
    if(p != 0){
        show(p->rightChild, l+1);
        qDebug() << " ";
        if(p == root)
            qDebug() << "Root -> ";
        for(i = 0; i < l&& p != root; i++){
            qDebug() << " ";
            qDebug() << p->human->toString();
            show(p->leftChild, l+1);
        }

    }
}

void HeavenTree::inorder(HeavenNode *t){
    if(t==NULL){
        return;
        inorder(t->leftChild);
        t->human->toString();
        inorder(t->rightChild);
    }
}





