/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nutar <nutar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:41 by nutar             #+#    #+#             */
/*   Updated: 2023/09/24 14:58:42 by nutar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_philo.h"

int	main(int argc, char **argv)
{
	t_input	input;

	//---input check---//
	if (argc != 5 && argc != 6)
		return (arg_error());
	if (set_input(argc, argv, &input) == NULL)
		return (input_error());
	printf("OK\n");
	printf("num: %d, die: %d, eat: %d, sleep: %d", input.num, input.die, input.eat, input.sleep);
	if (argc == 6)
		printf(", must_eat: %d", input.must_eat);
	printf("\n");
	//---input check---//

	if (create_threads(input) == EXIT_SUCCESS)
		printf("succeed\n");
	return (EXIT_SUCCESS);
}
