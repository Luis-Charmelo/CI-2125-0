void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int sum_red = 0, sum_green = 0, sum_blue = 0, count = 0;

            // Ajustar los límites del vecindario para los píxeles del borde
            int min_i = i - 1, max_i = i + 1;
            int min_j = j - 1, max_j = j + 1;

            if (i == 0) {
                min_i = 0;
            }
            if (i == height - 1) {
                max_i = height - 1;
            }
            if (j == 0) {
                min_j = 0;
            }
            if (j == width - 1) {
                max_j = width - 1;
            }

            for (int x = min_i; x <= max_i; x++) {
                for (int y = min_j; y <= max_j; y++) {
                    sum_red += temp[x][y].rgbtRed;
                    sum_green += temp[x][y].rgbtGreen;
                    sum_blue += temp[x][y].rgbtBlue;
                    count++;
                }
            }

            // Calcular el promedio y asignarlo al pixel
            image[i][j].rgbtRed = round(sum_red / (float)count);
            image[i][j].rgbtGreen = round(sum_green / (float)count);
            image[i][j].rgbtBlue = round(sum_blue / (float)count);
        }
    }
}
