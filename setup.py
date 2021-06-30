import re
from setuptools import setup, find_packages()

with open("requirments.txt") as f:
    requirments = f.read().splitlines()

setup(name='suspishous',
      author="Imposters and amongus",
      version="127.0.0.1"
      description="so suspishous",
      long_description=open("README.md").read()
      url="https://github.com/suspishous/suspishous",
      include_package_data=True,
      packages=find_packages(),
      zip_safe=False,
      python_requires='>=3.6'
      )
