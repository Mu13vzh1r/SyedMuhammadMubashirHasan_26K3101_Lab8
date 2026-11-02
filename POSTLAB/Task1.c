#include <stdio.h>

int main(){
    int marks[2][3][4] = {
        {
            {34, 53, 13, 67},
            {9, 76, 82, 23},
            {70, 37, 90, 12}
        },
        {
            {80, 88, 87, 82},
            {65, 79, 89, 90},
            {98, 95, 88, 81}
        }
    };

    int i, j, k, total = 0, avgCount = 0, highestStdMarks = 0, section;
    float avg, highestSecAvg = 0, secTotal = 0;

    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            printf("Student %d from Section %d\n", j + 1, i + 1);
            
            for (k = 0; k < 4; k++){
                total += marks[i][j][k];
            }
            
            avg = total / 4.0;
            secTotal += avg;
            
            printf("Total Marks: %d,\tAverage Marks: %.2f\n", total, avg);
            
            if (avg >= 50) {
                avgCount++;
            }
            
            if (total > highestStdMarks) {
                highestStdMarks = total;
            }

            total = 0;
        }
        
        printf("Highest Student Marks in Section %d: %d\n", i + 1, highestStdMarks);
        highestStdMarks = 0;

        if ((secTotal / 3.0) > highestSecAvg){
            highestSecAvg = secTotal / 3.0;
            section = i + 1;
        }
        
        secTotal = 0;
    }
    
    printf("Section %d has the highest overall average, %.2f\n", section, highestSecAvg);
    printf("Students with an average that is atleast 50: %d\n", avgCount);

    return 0;
}
