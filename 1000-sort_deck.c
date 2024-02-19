#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - function that compares two cards
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
 * Return: the result.
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card1 = *((const card_t **)a);
	const card_t *card2 = *((const card_t **)b);

	if (card1->kind != card2->kind)
	{
		return (card1->kind - card2->kind);
	}
	return (card_number_value(card1->value) - card_number_value(card2->value));
}

/**
 * card_number_value - the index of the card value.
 * @value: The value of the card.
 * Return: The index of the card value.
 */
int card_number_value(const char *value)
{
	const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	int i;
	deck_node_t *node = *deck;
	card_t *cards[52];

	for (i = 0; i < 52; i++)
	{
		cards[i] = (card_t *)node->card;
		node = node->next;
	}

	qsort(cards, 52, sizeof(card_t *), compare_cards);

	node = *deck;
	for (i = 0; i < 52; i++)
	{
		node->card = cards[i];
		node = node->next;
	}
}
