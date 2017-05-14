#!/usr/bin/python

import life
import unittest
import mock


class LifeTestCase(unittest.TestCase):

    def test_answer(self):
        self.assertEqual(42, life.answer())
