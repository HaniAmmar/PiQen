# PiQen

-   [What Is PiQen](#what-is-piqen)
-   [Features](#features)
-   [Usage](#usage)
    -   [Variable](#variable)
    -   [Math](#math)
    -   [Inline If](#inline-if)
    -   [Loop](#loop)
    -   [If Condition](#if-condition)
-   [Live Testing](#live-testing)
-   [Reference](#reference)
-   [Install](#install)
-   [License](#license)

## What Is PiQen

A Python module that uses [Qentem](https://github.com/HaniAmmar/Qentem-Engine) library for fast template rendering.

## Features

-   Fast template rendering.
-   Low memory usage.
-   Safe evaluation.
-   Variable replacement with HTML auto-escape.
-   Raw variable replacement **without** HTML auto-escape.
-   Nested loop (with data grouping and sorting).
-   Nested if condition.
-   Inline if.
-   Math tag.

## Usage

### Live Test

Templates can be tested live @ [JQen Tool](https://haniammar.github.io/JQen-Tool)

### Variable

```python
import PiQen

template = '''<div>{var:v1}</div>
<div>{var:sub-list1[sv1]}</div>
<div>{var:sub-list2[0]}</div>'''

data = '{"v1":"Qentem","sub-list1":{"sv1":"PiQen"},"sub-list2":[77]}'

print(PiQen.Render(template, data))


# To cache the template for multi-rendering, add a name:
# echo PiQen.Render(template, data, 'page1')
```

### Math

```python
import PiQen

template = '''
<div>0.1+0.2 is: {math: 0.1  +   0.2 }</div>
<div>{var:one}+{var:four}*{var:two}+{var:one} = {math:{var:one}+{var:four}*{var:two}+{var:one}}; (1+8+1)</div>
<div>6^2 = {math:6^2}</div>
<div>{var:one}+{var:three} = {math:{var:one}+{var:three}}</div>
<div>9 % 5 = {math:9 % 5}</div>
'''

data = '{"one":1,"two":2,"three":3,"four":4}'
print(PiQen.Render(template, data))
```

### Inline If

```python
import PiQen

template = '''
<div>{if case="{var:one} + {var:two} >= {var:three}" true="3" false="not three"}</div>
<div>{if case="{var:one}" true="{var:one}" false="not one"}</div>
{if case="{var:name} == Qentem" true="<div>Qentem!</div>"}
'''

data = '{"one":"1","two":"2","three":"3","name":"Qentem"}'

print(PiQen.Render(template, data))
```

### Loop

```python
import PiQen

template = '''
<loop set="object" value="item">
    <div>{var:item[var1]} {var:item[var2]} {var:item[var3]} {var:item[var4]}</div>
</loop>
<br />
<loop set="array" value="item">
    <div>{var:item[0]} {var:item[1]} {var:item[2]} {var:item[3]}</div>
</loop>
'''

data = '''
{
    "object": [
        {
            "var1": "value1",
            "var2": "value2",
            "var3": "value3",
            "var4": "value4"
        },
        {
            "var1": "value5",
            "var2": "value6",
            "var3": "value7",
            "var4": "value8"
        }
    ],
    "array": [
        [
            "value10",
            "value20",
            "value30",
            "value40"
        ],
        [
            "value100",
            "value200",
            "value300",
            "value400"
        ]
    ]
}
'''

print(PiQen.Render(template, data))
```

### If Condition

```python
import PiQen

template = '''
<if case="{var:0} == 0">
<div>Zero!</div>
</if>

<if case="{var:1} == 0">
Zero!
<else>
<div>Not {var:0} but {var:1}.</div>
</if>

<if case="{var:2} == 0">
Zero!
<else if case="{var:2} == 2">
<div>Two!</div>
<else>
Not zero or one.
</if>

<if case="{var:2} == 0">
Zero!
<else if case="{var:2} == 5">
Two!
<else if case="{var:3} == 3">
<div>{var:3}</div>
<else>
Not zero or one or two.
</if>
'''

data = '''[0,1,2,3]'''

print(PiQen.Render(template, data))
```

## Live Testing

Templates can be tested live @ [JQen Tool](https://haniammar.github.io/JQen-Tool)

## Reference

Syntax @ [Qentem-Engine/Template.md](https://github.com/HaniAmmar/Qentem-Engine/blob/main/Documentation/Template.md).

## Install

Make sure you have `setuptools` installed:

```shell
git submodule update --init
python setup.py build
sudo python setup.py install
```

## License

> MIT License
>
> Copyright (c) 2024 Hani Ammar
>
> Permission is hereby granted, free of charge, to any person obtaining a copy
> of this software and associated documentation files (the "Software"), to deal
> in the Software without restriction, including without limitation the rights
> to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
> copies of the Software, and to permit persons to whom the Software is
> furnished to do so, subject to the following conditions:
>
> The above copyright notice and this permission notice shall be included in all
> copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
> SOFTWARE.
