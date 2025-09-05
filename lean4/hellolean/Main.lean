import Hellolean

-- แสดงข้อความปกติ
def main : IO Unit := do
  IO.println "Hello Lean!"

  -- สมมติว่าฝนตก
  let rainHappens := true

  -- ใช้ฟังก์ชันตรวจสอบพื้นเปียก
  let wet := rain_then_wet_fun rainHappens

  if wet then
    IO.println "It is raining → the ground is wet ✅"
  else
    IO.println "It is not raining → the ground stays dry 🌤️"

-- แปลง theorem เป็น function ที่ return Bool
def rain_then_wet_fun (r : Bool) : Bool :=
  if r then true else false  -- ถ้าฝนตก → พื้นเปียก

-- ตัวอย่าง theorem ธรรมดา (สำหรับ logic)
theorem rain_implies_wet (R W : Prop) (h : R → W) : R → W :=
  fun r => h r

-- Named proposition (True/False แทนได้)
def Rain : Prop := True
def Wet : Prop := True

theorem rain_then_wet (h : Rain) : Wet := by
  trivial
