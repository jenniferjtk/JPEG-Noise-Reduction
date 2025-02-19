from PIL import Image
import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: python convertJPG.py <input.jpg>")
        sys.exit(1)

    input_filename = sys.argv[1]  # Get input file from command line
    output_ppm = "input.ppm"  # Convert JPEG to PPM

    # Open and convert JPEG to RGB
    image = Image.open(input_filename).convert("RGB")

    # Save as PPM
    image.save(output_ppm)
    print(f"✅ Converted {input_filename} to {output_ppm}")

if __name__ == "__main__":
    main()
