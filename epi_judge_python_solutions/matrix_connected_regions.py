import collections
from sys import exit

from test_framework import generic_test, test_utils


def flip_color(x, y, image):
    color = image[x][y]
    q = collections.deque([(x, y)])
    image[x][y] = 1 - image[x][y]  # Flips.
    while q:
        x, y = q.popleft()
        for next_x, next_y in ((x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)):
            if (0 <= next_x < len(image) and 0 <= next_y < len(image[next_x])
                    and image[next_x][next_y] == color):
                # Flips the color.
                image[next_x][next_y] = 1 - image[next_x][next_y]
                q.append((next_x, next_y))


def flip_color_wrapper(x, y, image):
    flip_color(x, y, image)
    return image


if __name__ == '__main__':
    exit(generic_test.generic_test_main('painting.tsv', flip_color_wrapper))