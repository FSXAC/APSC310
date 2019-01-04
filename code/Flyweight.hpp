#include <unordered_map>

int getStringHash(const std::string& str)
{
	int hash = 13;
	for (int i = 0; i < str.length(); i++)
	{
		hash = hash * 101 + str[i];
	}
	return hash;
}

// Intrinsic data
class Texture
{
public:
	Texture(const str::string& path) : m_texture(path) { }
private:
	str::string m_texture;
};

// Extrinsic wrapper
class TextureWrapper
{
public:
	TextureWrapper(Texture* texture) : m_texture(texture) { }
	void setPos(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
private:
	Texture* m_texture;
	int m_x;
	int m_y;
};

class TextureFlyweightFactory
{
public:
	static TextureWrapper* getTexture(const std::string& path, int x, int y)
	{
		TextureWrapper newTexture;

		// Check if texture is cached by comparing hashes
		const int textureHash = getStringHash(path);
		if (m_cachedTextures.find(textureHash) != m_cachedTextures.end())
		{
			// Exists
			newTexture = new TextureWrapper(m_cachedTextures[textureHash]);
		}
		else
		{
			// Does not exist, create new then add to cache
			Texture *texture = new Texture(path);
			newTexture = new TextureWrapper(texture);
			m_cachedTextures[textureHash] = texture;
		}

		newTexture->setPos(x, y);
		return newTexture;
	}

private:
	static std::unordered_map<int, Texture* m_cachedTextures;
};

// Example
int main(void)
{
	std::string texture1 = "player.png";
	std::string texture2 = "enemy.png";

	// Create texture
	TextureWrapper textures[5] = {

		// First instance (expect creating new texture resources)
		new TextureFlyweightFactory::getTexture(texture1, 0, 0),
		new TextureFlyweightFactory::getTexture(texture2, 10, 10),

		// Repeated instances (expect sharing Texture resource)
		new TextureFlyweightFactory::getTexture(texture1, 10, 0),
		new TextureFlyweightFactory::getTexture(texture1, 0, 10),
		new TextureFlyweightFactory::getTexture(texture2, 20, 20)
	};
	
	return 0;
}