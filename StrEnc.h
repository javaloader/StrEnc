#include "Includes.h"

#if !defined(STR_ENC)
#define STR_ENC

class StrEnc {
private:
    char *s;
    int n;
public:
    StrEnc(const char *str, const char *key, int len);

    ~StrEnc();

    const char *c_str();
};

__attribute__((always_inline))StrEnc::StrEnc(const char *str, const char *key, int len) : n(len) {
    s = new char[len + 1];
    for (int i = 0; i < len; i++) {
        s[i] = str[i] ^ key[i];
    }
    s[len] = 0;
}

__attribute__((always_inline))StrEnc::~StrEnc() {
    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }
}

__attribute__((always_inline))const char *StrEnc::c_str() {
    //LOGI("StrEnc: %s", s);
    return s;
}

#endif