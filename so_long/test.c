/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkoujan <kkoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:00:00 by kkoujan           #+#    #+#             */
/*   Updated: 2025/01/02 15:46:43 by kkoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <string.h>

typedef struct s_test_result
{
    char    *map_name;
    int     expected_result;
    int     actual_result;
}   t_test_result;

void    print_test_result(t_test_result result)
{
    printf("\nTesting map: %s\n", result.map_name);
    printf("Expected result: %d\n", result.expected_result);
    printf("Actual result: %d\n", result.actual_result);
    
    if (result.expected_result == result.actual_result)
        printf("✅ Test passed!\n");
    else
        printf("❌ Test failed!\n");
    printf("----------------------------------------\n");
}

t_test_result    run_test(char *map_path, int expected)
{
    t_test_result    result;
    char            **map;

    result.map_name = map_path;
    result.expected_result = expected;
	int fd = open(map_path, O_RDONLY, 0777);
    map = read_map(fd,map_path);
    if (!map)
    {
        result.actual_result = 0;
        return (result);
    }
    result.actual_result = check_map(map);
    free_arr(map, -1);  // Assuming your free_arr handles NULL terminator
    return (result);
}

char    *create_map_path(int map_number)
{
    static char map_path[256];
    char        number[4];

    snprintf(map_path, sizeof(map_path), "maps/map");
    snprintf(number, sizeof(number), "%d", map_number);
    strcat(map_path, number); 
    strcat(map_path, ".ber");
    return (map_path);
}

int main(void)
{
    t_test_result    results[16];
    int             test_count;
    int             passed_count;
    int             i;

    // Expected results for each map (1 for valid, 0 for invalid)
    int expected_results[16] = {
        1,  // map1.ber - Valid basic map
        1,  // map2.ber - Invalid: missing exit
        1,  // map3.ber - Invalid: duplicate player
        0,  // map4.ber - Valid complex map
        0,  // map5.ber - Invalid: not rectangular
        0,  // map6.ber - Invalid: no valid path
        0,  // map7.ber - Invalid: missing collectible
        0,  // map8.ber - Invalid: not surrounded by walls
        0,  // map9.ber - Valid minimal map
        0,  // map10.ber - Invalid: invalid character
        0,  // map11.ber - Invalid: no player
        0,  // map12.ber - Invalid: duplicate exit
        0,  // map13.ber - Valid large map
        1,  // map14.ber - Invalid: empty file
        1,  // map15.ber - Invalid: missing wall
        0   // map16.ber - Valid complex path map
    };

    test_count = 0;
    passed_count = 0;
    i = 0;

    // Run tests for each map
    while (i < 16)
    {
        results[i] = run_test(create_map_path(i + 1), expected_results[i]);
        if (results[i].actual_result == results[i].expected_result)
            passed_count++;
        test_count++;
        i++;
    }

    // Print summary of all tests
    printf("\n=== Test Summary ===\n");
    i = 0;
    while (i < test_count)
    {
        print_test_result(results[i]);
        i++;
    }
    
    printf("\nTotal tests: %d\n", test_count);
    printf("Passed tests: %d\n", passed_count);
    printf("Failed tests: %d\n", test_count - passed_count);
    printf("Success rate: %.2f%%\n", (float)passed_count / test_count * 100);

    return (0);
}