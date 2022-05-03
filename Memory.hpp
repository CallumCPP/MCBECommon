#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <Windows.h>
#include <Psapi.h>
#include <vector>

#define INRANGE(x,a,b) (x >= a && x <= b)
#define GET_BYTE( x )  (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )  (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

namespace Common {
    namespace Mem {
        uintptr_t findSig(const char* sig, const char* module = "Minecraft.Windows.exe") {
            const char* pattern = sig;
            uintptr_t firstMatch = 0;
            const uintptr_t rangeStart = (uintptr_t)GetModuleHandleA(module);

            MODULEINFO miModInfo;
            GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
            
            const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;
            BYTE patByte = GET_BYTE(pattern);
            const char* oldPat = pattern;

            for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++){
                if (!*pattern) return firstMatch;
                while (*(PBYTE)pattern == ' ') pattern++;
                if (!*pattern) return firstMatch;
                
                if (oldPat != pattern){
                    oldPat = pattern;
                    if (*(PBYTE)pattern != '\?') patByte = GET_BYTE(pattern);
                }

                if (*(PBYTE)pattern == '\?' || *(BYTE*)pCur == patByte){
                    if (!firstMatch) firstMatch = pCur;
                    if (!pattern[2]) return firstMatch;
                    
                    pattern += 2;
                } else {
                    pattern = sig;
                    firstMatch = 0;
                }
            }
            return NULL;
        }
        
        uintptr_t findMultiLvlPtr(uintptr_t baseAddr, std::vector<unsigned int> offsets) {
            uintptr_t res = NULL;

            if(baseAddr != NULL) {
                auto curr = baseAddr;
                for(auto I = 0; I < offsets.size(); I++) {
                    if((uintptr_t*)curr == nullptr || *(uintptr_t*)curr == NULL) break;
                    
                    curr = *(uintptr_t*)curr;
                    if((uintptr_t*)(curr + offsets[I]) == nullptr || *(uintptr_t*)(curr + offsets[I]) == NULL) break;
                    
                    curr += offsets[I];
                }
                if(curr != NULL)
                    res = curr;
            }

            return res;
        }
    }
}

#endif /* MEMORY_HPP */
