#!/usr/bin/env python
# -*- coding: utf-8 -*-

import pygame
from pygame.locals import *
import sys
import random


SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480
FPS = 30

WHITE = 255,255,255
BLACK = 0,0,0
PURPLE = 102,0,102

def rand(a,b):
	return a+b*random.random()

class Drop:
	def __init__(self,x,y):
		self.k = rand(1, 4)
		self.x = x
		self.y = y
		self.w = self.k
		self.h = self.w*6
		self.vel = self.w*3
		self.image = pygame.Surface((self.w, self.h))
		self.color = PURPLE
	def draw(self,screen):
		self.image.fill(self.color)
		screen.blit(self.image, (self.x, self.y))
	def update(self):
		self.y += self.vel
	def out(self):
		if (self.y > SCREEN_HEIGHT):
			return True
		else:
			return False


def main():
	pygame.init()

	clock 	= pygame.time.Clock()
	screen 	= pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
	background = pygame.Surface(screen.get_size())

	drops = list()
	paused = True

	while True:
		pygame.display.set_caption("Tutorial | FPS: "+str(round(clock.get_fps(),2)))
		milliseconds = clock.tick(FPS)

		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
			if event.type == pygame.MOUSEBUTTONDOWN:
				paused = not paused
				

		background.fill(WHITE)
		screen.blit(background, (0, 0))

		if (not paused):
			drops.append(Drop(SCREEN_WIDTH*random.random(), 0))
			drops.append(Drop(SCREEN_WIDTH*random.random(), 0))
			drops.append(Drop(SCREEN_WIDTH*random.random(), 0))
			drops.append(Drop(SCREEN_WIDTH*random.random(), 0))
			drops.append(Drop(SCREEN_WIDTH*random.random(), 0))
			drops.append(Drop(SCREEN_WIDTH*random.random(), 0))

			erase = list()
			for i in xrange(len(drops)):
				drops[i].update()
				if drops[i].out():
					erase.insert(0,i)
			for i in erase:
				del drops[i]

		for i in xrange(len(drops)):
			drops[i].draw(screen)
		print len(drops)

		pygame.display.flip()


if __name__ == "__main__":
	main()