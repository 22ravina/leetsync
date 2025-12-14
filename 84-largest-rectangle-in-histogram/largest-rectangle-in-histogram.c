
int largestRectangleArea(int* heights, int heightsSize) {
    int *stack = (int *)malloc(sizeof(int) * (heightsSize + 1));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        int currHeight;

        if (i == heightsSize)
            currHeight = 0;      
        else
            currHeight = heights[i];

        while (top != -1 && currHeight < heights[stack[top]]) {
            int h = heights[stack[top]];
            top--;

            int width;
            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            int area = h * width;
            if (area > maxArea)
                maxArea = area;
        }

        top++;
        stack[top] = i;
    }

    free(stack);
    return maxArea;
}
