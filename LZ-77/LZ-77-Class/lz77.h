#ifndef LZ77_H
#define LZ77_H

#include <string>
#include <vector>

class LZ77 {
public:
    struct Match {
        int offset;
        int length;
        char nextChar;
    };

    std::vector<Match> compress(const std::string& input, int searchBufferSize, int lookAheadBufferSize);
    std::string decompress(const std::vector<Match>& matches);

private:
    Match findLongestMatch(const std::string& input, int currentIndex, int searchBufferSize, int lookAheadBufferSize);
};

#endif // LZ77_H
