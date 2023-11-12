 auto it = que.front();
            que.pop();

            int currStep = it.first;
            int currNode = it.second;

            for (auto node : arr) {
                
                int currNum = (currNode * node) % mod;
                
                if (currStep + 1 < steps[currNum]) {
                    
                    steps[currNum] = currStep + 1;

                    if (currNum == end)return currStep + 1;

                    que.push({currStep + 1, currNum});
                    