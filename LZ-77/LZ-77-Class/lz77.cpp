#include "LZ77.h"
#include <algorithm>

LZ77::Match LZ77::findLongestMatch(const std::string& input, int currentIndex, int searchBufferSize, int lookAheadBufferSize) {
    Match bestMatch = {0, 0, input[currentIndex]};
    int searchStartIndex = std::max(0, currentIndex - searchBufferSize);
    int searchEndIndex = currentIndex;

    for (int i = searchStartIndex; i < searchEndIndex; ++i) {
        int matchLength = 0;
        while (matchLength < lookAheadBufferSize &&
               currentIndex + matchLength < input.size() &&
               input[i + matchLength] == input[currentIndex + matchLength]) {
            ++matchLength;
        }

        if (matchLength > bestMatch.length) {
            bestMatch.offset = currentIndex - i;
            bestMatch.length = matchLength;
            if (currentIndex + matchLength < input.size()) {
                bestMatch.nextChar = input[currentIndex + matchLength];
            }
        }
    }

    return bestMatch;
}

std::vector<LZ77::Match> LZ77::compress(const std::string& input, int searchBufferSize, int lookAheadBufferSize) {
    std::vector<Match> matches;
    int currentIndex = 0;

    while (currentIndex < input.size()) {
        Match match = findLongestMatch(input, currentIndex, searchBufferSize, lookAheadBufferSize);
        matches.push_back(match);
        currentIndex += match.length + 1;
    }

    return matches;
}

std::string LZ77::decompress(const std::vector<Match>& matches) {
    std::string output;

    for (const Match& match : matches) {
        int start = output.size() - match.offset;
        for (int i = 0; i < match.length; ++i) {
            output += output[start + i];
        }
        output += match.nextChar;
    }

    return output;
}
