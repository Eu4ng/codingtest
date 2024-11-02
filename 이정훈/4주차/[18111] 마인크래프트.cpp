#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 변수 선언 및 초기화
    int n, m, b;
    cin >> n >> m >> b;
    
    vector<vector<int>> map(n, vector<int>(m, -1));

    // 입력 분석
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            int input;
            cin >> input;

            map[i][j] = input;

            // 필드 블록 개수 합산
            count += input;
        }
    }

    // 평탄화 높이 후보 구하기
    vector<int> heights;
    heights.reserve(2);

    int h = count / (n * m);
    heights.push_back(h);

    // 인벤토리 내의 블록까지 사용하여 쌓을 수 있는 모든 높이 추가
    int max_offset = (count % (n * m) + b) / (n * m);
    for(int i = 1; i <= max_offset; ++i)
    {
        heights.push_back(h + i);
    }

    // 정답 변수 선언
    int final_height = -1;
    int final_time = -1;

    for(int height : heights)
    {
        int block_to_remove = 0; // 제거해야하는 블록 수
        int block_to_add = 0; // 추가해야하는 블록 수
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int offset = map[i][j] - height;
                if(offset == 0)
                {
                    continue;
                }
                else if(offset > 0)
                {
                    block_to_remove += offset;
                }
                else
                {
                    block_to_add -= offset; // offset < 0
                }
            }
        }

        // 인벤토리 내 블록 수와 평탄화 작업 중 획득한 블록 수의 합이 쌓을 때 필요한 블록 수보다 적은 경우 평탄화 작업이 불가능
        int time = block_to_add + block_to_remove * 2;
        if(block_to_add > block_to_remove + b)
        {
            continue; // 블록 수 불충분으로 인한 평탄화 작업 불가능
        }
        else if(height > 256)
        {
            continue; // 256 높이 초과로 인한 평탄화 작업 불가능
        }
        else
        {
            if(final_time == -1 || time < final_time)
            {
                final_height = height;
                final_time = time;
            }
        }
    }

    // 정답 출력
    cout << final_time << " " << final_height;

    return 0;
}

// 모든 좌표의 개수를 다 더한 다음 평균에 가장 가까운 걸 찾아라

// 