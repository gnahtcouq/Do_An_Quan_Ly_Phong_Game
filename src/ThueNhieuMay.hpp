#pragma once
#include "MotMayTinh.hpp"
#include "ThueMotMay.hpp"

struct Node {
    ThueMotMay data;
    Node *pNext;
};

struct ThueNhieuMay {
    Node *pHead;
    Node *pTail;
};

void createList(ThueNhieuMay &thueNhieuMay);
Node *createNode(ThueMotMay value);
void addNodeInTail(ThueNhieuMay &thueNhieuMay, ThueMotMay thueMotMay);
void removeNodeInHead(ThueNhieuMay &thueNhieuMay);
void removeNodeInTail(ThueNhieuMay &thueNhieuMay);
void giaiPhongVungNhoDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay);

void createList(ThueNhieuMay &thueNhieuMay) {
    thueNhieuMay.pHead = NULL;
    thueNhieuMay.pTail = NULL;
}

Node *createNode(ThueMotMay value) {
    Node *p = (Node *)calloc(1, sizeof(Node));
    if (p == NULL) {
        cout << "\n\t(!) Khong du bo nho (!)";
        return NULL;
    } else {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void addNodeInTail(ThueNhieuMay &thueNhieuMay, ThueMotMay thueMotMay) {
    Node *p = createNode(thueMotMay);
    if (thueNhieuMay.pHead == NULL)
        thueNhieuMay.pHead = thueNhieuMay.pTail = p;
    else {
        thueNhieuMay.pTail->pNext = p;
        thueNhieuMay.pTail = p;
    }
}

void removeNodeInHead(ThueNhieuMay &thueNhieuMay) {
    if (thueNhieuMay.pHead == NULL)
        return;
    else {
        Node *p = thueNhieuMay.pHead;
        thueNhieuMay.pHead = p->pNext;
        free(p);
    }
}

void removeNodeInTail(ThueNhieuMay &thueNhieuMay) {
    if (thueNhieuMay.pHead == NULL)
        return;
    else if (thueNhieuMay.pHead == thueNhieuMay.pTail)
        removeNodeInHead(thueNhieuMay);
    else {
        for (Node *t = thueNhieuMay.pHead; t != NULL; t = t->pNext) {
            if (t->pNext == thueNhieuMay.pTail) {
                free(thueNhieuMay.pTail);
                t->pNext = NULL;
                thueNhieuMay.pTail = t;
                return;
            }
        }
    }
}

void giaiPhongVungNhoDanhSachNguoiThue(ThueNhieuMay &thueNhieuMay) {
    Node *t = NULL;
    while (thueNhieuMay.pHead != NULL) {
        t = thueNhieuMay.pHead;
        thueNhieuMay.pHead = thueNhieuMay.pHead->pNext;
        free(t);
    }
}