from PIL import Image, ImageDraw, ImageFont
import numpy as np

text = "ผมยาวดิ"

# ใช้ฟอนต์ที่มีตัวอักษรไทยจริง ๆ
font_path = "/System/Library/Fonts/Supplemental/Ayuthaya.ttf"
font = ImageFont.truetype(font_path, 80)

# --- แก้ตรงนี้ ---
bbox = font.getbbox(text)
w, h = bbox[2] - bbox[0], bbox[3] - bbox[1]
# -----------------

img = Image.new("L", (w+20, h+20), 255)
draw = ImageDraw.Draw(img)
draw.text((10, 10), text, font=font, fill=0)

scale = 0.5   # ขยายหน่อยให้คม
img_small = img.resize((int(img.width*scale), int(img.height*scale)))

arr = np.array(img_small)

chars = " .:-=+*#%@"
step = 256 // len(chars)
out_lines = []
for row in arr:
    line = "".join(chars[min(len(chars)-1, x // step)] for x in row)
    out_lines.append(line)

for l in out_lines:
    print(l)